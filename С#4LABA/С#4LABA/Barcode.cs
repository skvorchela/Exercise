namespace BarcodeLibrary
{
    public class Barcode : IBarcode
    {
        private string text;
        public string Text
        {
            get => text;
            set
            {
                if (value == text) return;

                text = value;
                Code = BarcodeHelper.GetCode(value);
            }
        }

        public string Code { get; private set; }

        public static BarcodeType BarcodeType { get; set; } = BarcodeType.Full;

        public Barcode(string text)
        {
            Text = text;
            Code = BarcodeHelper.GetCode(text);
        }

        public override string ToString()
        {
            return BarcodeType switch
            {
                BarcodeType.Barcode => Code,
                BarcodeType.Text => $"* {Text} *",
                _ => Code + "\n" + $"* {Text} *",
            };
        }
    }
}
