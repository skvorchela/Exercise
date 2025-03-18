using DataDevices;
using Showcase;

public static class ShowcaseExtensions
{
    public static void UpdateDeviceBarcode(this IDataDevice device, int showcaseId, int position)
    {
        device.Barcode.Text = $"{device.Id} {showcaseId} {position}";
    }

    public static void UpdateDeviceBarcode(this IDataDevice device, Showcase<IDataDevice> showcase, int position)
    {
        device.UpdateDeviceBarcode(showcase.Id, position);
    }
}
