using BarcodeLibrary;
using System;

namespace DataDevices
{
    public abstract class DataDevices : IDataDevice
    {
        private int id;
        public int Id
        {
            get => id;
            set
            {
                if (value == id) return;
                int oldId = id;
                id = value;
                OnIdChanged(new DeviceIdChangedEventArgs(oldId, id));
                Barcode.Text = id.ToString();
            }
        }
        public string Name { get; set; }
        public IBarcode Barcode { get; set; }
        public event EventHandler<DeviceIdChangedEventArgs> IdChanged; // Событие

        protected DataDevices(int id, string name)
        {
            Barcode = new Barcode(id.ToString());
            Id = id;
            Name = name;
        }

        protected abstract string GetDeviceType();
        protected abstract string GetCharacteristics();

        protected virtual void OnIdChanged(DeviceIdChangedEventArgs e)
        {
            IdChanged?.Invoke(this, e);
        }

        public override string ToString()
        {
            return $"{GetDeviceType()}: {Name}\n{GetCharacteristics()}\nШтрихкод:\n{Barcode}\n";
        }
    }
}
