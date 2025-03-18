using BarcodeLibrary;

namespace DataDevices
{
    public interface IDataDevice
    {
        int Id { get; set; }
        string Name { get; set; }
        IBarcode Barcode { get; set; }
        event EventHandler<DeviceIdChangedEventArgs> IdChanged; // Добавлено событие
    }
}
