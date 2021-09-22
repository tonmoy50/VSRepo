using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace StockMarket.Models
{
    public class JsonModel
    {
        [JsonPropertyName("date")]
        public DateTime Date { get; set; }
        [JsonPropertyName("trade_code")]
        public string Trade_code { get; set; }
        [JsonPropertyName("high")]
        public string High { get; set; }
        [JsonPropertyName("low")]
        public string Low { get; set; }
        [JsonPropertyName("open")]
        public string Open { get; set; }
        [JsonPropertyName("close")]
        public string Close { get; set; }
        [JsonPropertyName("volume")]
        public string Volume { get; set; }

        public override string ToString() => JsonSerializer.Serialize<JsonModel>(this);



    }
}
