using Microsoft.AspNetCore.Hosting;
using StockMarket.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Text.Json;
using System.Threading;

namespace StockMarket.Services
{
    public class JsonService
    {
        public JsonService(IWebHostEnvironment webHostEnvironment)
        {
            WebHostEnvironment = webHostEnvironment;
        }

        public IWebHostEnvironment WebHostEnvironment { get; }
        public string JsonFileName
        {
            get
            {
                return Path.Combine(WebHostEnvironment.WebRootPath, "data", "stock_market_data.json");
            }
        }

        public IEnumerable<JsonModel> GetProducts()
        {
            using (var jsonfilereader = File.OpenText(JsonFileName))
            {
                return JsonSerializer.Deserialize<JsonModel[]>(jsonfilereader.ReadToEnd(),
                    new JsonSerializerOptions
                    {
                        PropertyNameCaseInsensitive = true
                    });
            }
        }

        
    }
}
