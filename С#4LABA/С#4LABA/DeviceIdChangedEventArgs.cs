using System;

namespace DataDevices
{
    public class DeviceIdChangedEventArgs : EventArgs
    {
        public int OldId { get; }
        public int NewId { get; }

        public DeviceIdChangedEventArgs(int oldId, int newId)
        {
            OldId = oldId;
            NewId = newId;
        }
    }
}
