using System;
using BarcodeLibrary;
using DataDevices;
using Showcase;

namespace InventorySystem
{
    class Program
    {
        static void Main(string[] args)
        {
            var barcode = new Barcode("");
            Showcase<IDataDevice> showcase1 = 10;
            Showcase<IDataDevice> showcase2 = 5;

            while (true)
            {
                Console.WriteLine("Выберите действие:");
                Console.WriteLine("1. Добавить Товар");
                Console.WriteLine("2. Удалить товар");
                Console.WriteLine("3. Поменять id товара или полку товара");
                Console.WriteLine("4. Посмотреть витрину");
                Console.WriteLine("0. Выйти");

                var choice = Console.ReadLine();
                switch (choice)
                {
                    case "1":
                        AddDevice(showcase1);
                        break;
                    case "2":
                        RemoveDevice(showcase1);
                        break;
                    case "3":
                        UpdateDevice(showcase1);
                        break;
                    case "4":
                        ViewShowcase(showcase1);
                        break;
                    case "0":
                        return;
                    default:
                        Console.WriteLine("Неверный выбор, попробуйте снова.");
                        break;
                }
            }
        }

        static void AddDevice(Showcase<IDataDevice> showcase)
        {
            Console.Write("Введите ID устройства: ");
            int id = int.Parse(Console.ReadLine());
            Console.Write("Введите название устройства: ");
            string name = Console.ReadLine();
            Console.Write("Введите скорость записи: ");
            double writing = double.Parse(Console.ReadLine());
            Console.Write("Введите скорость чтения: ");
            double reading = double.Parse(Console.ReadLine());
            Console.Write("Введите объем памяти: ");
            int memory = int.Parse(Console.ReadLine());

            var device = new SSD(id, name, writing, reading, memory);
            showcase.AddDevice(device);

            Console.WriteLine("Устройство добавлено.");
        }

        static void RemoveDevice(Showcase<IDataDevice> showcase)
        {
            Console.Write("Введите индекс устройства для удаления: ");
            int index = int.Parse(Console.ReadLine());
            showcase.RemoveDevice(index);

            Console.WriteLine("Устройство удалено.");
        }

        static void UpdateDevice(Showcase<IDataDevice> showcase)
        {
            Console.Write("Введите индекс устройства для изменения: ");
            int index = int.Parse(Console.ReadLine());
            Console.Write("Введите новое ID устройства: ");
            int newId = int.Parse(Console.ReadLine());
            var device = showcase.RemoveDevice(index);

            if (device != null)
            {
                device.Id = newId;
                showcase.AddDevice(device, index);
                Console.WriteLine("ID устройства обновлено.");
            }
            else
            {
                Console.WriteLine("Устройство не найдено.");
            }
        }

        static void ViewShowcase(Showcase<IDataDevice> showcase)
        {
            Console.WriteLine(showcase.ToString());
        }
    }
}
