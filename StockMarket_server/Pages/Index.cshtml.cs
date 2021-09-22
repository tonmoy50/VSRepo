using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using Microsoft.EntityFrameworkCore;
//using BindingDataFromDatabase.Model;
using StockMarket_server.Model;
using System.Text.Json.Serialization;
using System.Text.Json;
//using Newtonsoft.Json;

namespace StockMarket_server.Pages
{
    public class IndexModel : PageModel
    {
        //private readonly ILogger<IndexModel> _logger;
        private readonly sqlConnection _db;

        public IndexModel(sqlConnection db)
        {
            _db = db;
        }

        public IEnumerable<sqlModel> GetRecords { get; set; }

        
        public string SelectedData { get; set; }
        public string temp_data { get; set; }
        public HashSet<string> Trades
        {
            get
            {

                HashSet<string> names = new HashSet<string>();
                //List<string> names = new List<string>();
                IEnumerable<sqlModel> get_trade_name = _db.StockData.FromSqlRaw("SELECT * FROM dbo.StockData");

                foreach (var item in get_trade_name)
                {
                    names.Add(item.Trade_Code);
                }

                return names;
            }
        }


        //public var GetChartData { get; set; }

        

        public void OnGet()
        {

            if (Request.Query["trade_codes"] == "")
            {
                SelectedData = "1JANATAMF";
            }
            else
            {
                SelectedData = Request.Query["trade_codes"];
            }

            GetRecords = _db.StockData.FromSqlRaw("SELECT * FROM dbo.StockData WHERE trade_code={0} ", SelectedData);

            //GetChartData = GetRecords.ToList();
            //GetChartData = Json(GetRecords.ToList());
            
        }

        

        /*public async Task OnGet()
        {
            GetRecords = await _db.Sheet2.ToListAsync();


            //var cont = context

            if (Request.Query["trade_codes"] == "")
            {
                SelectedData = "1JANATAMF";
            }
            else
            {
                SelectedData = Request.Query["trade_codes"];
            }
        }*/


    }
}
