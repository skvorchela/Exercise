using DataDevices;
using System;

namespace Showcase
{
    public delegate void ShowcaseIdChangedEventHandler<T>(Showcase<T> showcase) where T : class, IDataDevice;

    public interface IShowcase<T> where T : class // Ограничение, чтобы T был ссылочным типом
    {
        void AddDevice(T device);
        void AddDevice(T device, int index);
        T? RemoveDevice();
        T? RemoveDevice(int index);
        void ReplaceDevice(int index, T newDevice);
        void SwapDevices(int index1, int index2);
        int FindById(int deviceId);
        int FindByName(string name);
        void SortById();
        void SortByName();
        string ToString();
    }

    public class Showcase<T> : IShowcase<T> where T : class, IDataDevice
    {
        private static int currentId = 1;
        private int id;
        private readonly T[] devices;
        private int capacity;

        public event ShowcaseIdChangedEventHandler<T>? ShowcaseIdChanged;

        public int Id
        {
            get => id;
            set
            {
                if (value == id) return;
                int oldId = id;
                id = value;
                ShowcaseIdChanged?.Invoke(this);
                UpdateBarcode();
            }
        }

        private Showcase(int id, int capacity)
        {
            this.id = id;
            this.capacity = capacity;
            devices = new T[capacity];
        }

        public static implicit operator Showcase<T>(int capacity)
        {
            return new Showcase<T>(currentId++, capacity);
        }

        private void UpdateBarcode(T? device, int index)
        {
            if (device != null)
            {
                device.UpdateDeviceBarcode(this.Id, index); // Передача id витрины вместо объекта
            }
        }

        private void UpdateBarcode()
        {
            for (int i = 0; i < capacity; i++)
            {
                UpdateBarcode(devices[i], i);
            }
        }

        public T? this[int index]
        {
            get
            {
                if (index >= 0 && index < capacity && devices[index] != null)
                {
                    var device = devices[index];
                    devices[index] = default!;
                    return device;
                }
                return default!;
            }
            set
            {
                if (index >= 0 && index < capacity)
                {
                    devices[index] = value!;
                    if (value != null)
                    {
                        UpdateBarcode(value, index);
                    }
                }
            }
        }

        public void AddDevice(T device)
        {
            for (int i = 0; i < capacity; i++)
            {
                if (devices[i] == null)
                {
                    this[i] = device;
                    break;
                }
            }
        }

        public void AddDevice(T device, int index)
        {
            if (index >= 0 && index < capacity && devices[index] == null)
            {
                this[index] = device;
            }
        }

        public T? RemoveDevice()
        {
            for (int i = 0; i < capacity; i++)
            {
                if (devices[i] != null)
                {
                    var device = devices[i];
                    this[i] = default!;
                    return device;
                }
            }
            return default!;
        }

        public T? RemoveDevice(int index)
        {
            if (index >= 0 && index < capacity && devices[index] != null)
            {
                var device = devices[index];
                devices[index] = null;
                return device;
            }
            return default!;
        }

        public void ReplaceDevice(int index, T newDevice)
        {
            this[index] = newDevice;
        }

        public void SwapDevices(int index1, int index2)
        {
            (this[index1], this[index2]) = (this[index2], this[index1]);
        }

        public int FindById(int deviceId)
        {
            return Find((device, value) => device?.Id.ToString() == value, deviceId.ToString());
        }

        public int FindByName(string name)
        {
            return Find((device, value) => device?.Name == value, name);
        }

        public void SortById()
        {
            Sort((p1, p2) => (p1?.Id ?? int.MaxValue).CompareTo(p2?.Id ?? int.MaxValue));
        }

        public void SortByName()
        {
            Sort((p1, p2) => string.Compare(p1?.Name ?? "\uFFFF", p2?.Name ?? "\uFFFF", StringComparison.Ordinal));
        }

        private void Sort(SortDelegate<T> sortDelegate)
        {
            Array.Sort(devices, (p1, p2) => sortDelegate(p1, p2));
            UpdateBarcode();
        }

        private int Find(FindDelegate<T> findDelegate, string value)
        {
            for (int i = 0; i < capacity; i++)
            {
                if (findDelegate(devices[i], value))
                {
                    return i;
                }
            }
            return -1;
        }

        public override string ToString()
        {
            var result = $"Витрина {id}:\n";
            for (int i = 0; i < capacity; i++)
            {
                result += devices[i]?.ToString() ?? $"Ячейка {i}: Пусто\n";
            }
            return result;
        }
    }

    public delegate int SortDelegate<T>(T x, T y);
    public delegate bool FindDelegate<T>(T device, string value);
}
