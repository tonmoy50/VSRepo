using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.TagHelpers;
using Microsoft.Extensions.Logging;
using StockMarket.Models;
using StockMarket.Services;

namespace StockMarket.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;
        public JsonService DataService;
        public IEnumerable<JsonModel> Datas { get; private set; }
        //public IEnumerable

        [BindProperty]
        public HashSet<string> Trade_Code
        {
            get
            {
                HashSet<string> names = new HashSet<string>();

                foreach (var item in DataService.GetProducts())
                {
                    names.Add(item.Trade_code);
                }

                return names;
            }
        }

        public string SelectedData { get; set; }




        public IndexModel(
            ILogger<IndexModel> logger,
            JsonService dataservice)
        {
            _logger = logger;
            DataService = dataservice;
            //TradeNames = Names;
        }

        public void OnGet()
        {
            Datas = DataService.GetProducts();
            if (Request.Query["trade_codes"] == "")
            {
                SelectedData = "1JANATAMF";
            }
            else
            {
                SelectedData = Request.Query["trade_codes"];
            }
            
            

        }

        

    }
}
