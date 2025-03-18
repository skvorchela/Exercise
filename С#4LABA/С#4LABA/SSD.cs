using System;

namespace DataDevices
{
    public class SSD : DataDevices
    {
        public double Writing { get; }
        public double Reading { get; }
        public int Memory { get; }

        public SSD(int id, string name, double writing, double reading, int memory)
            : base(id, name)
        {
            Writing = writing;
            Reading = reading;
            Memory = memory;
        }

        protected override string GetDeviceType()
        {
            return "SSD";
        }

        protected override string GetCharacteristics()
        {
            return $"Запись: {Writing}\nЧтение: {Reading}\nКол-во памяти: {Memory}";
        }
    }
}
