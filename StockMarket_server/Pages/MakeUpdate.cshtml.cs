using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Data.SqlClient;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualBasic;
using StockMarket_server.Model;

namespace StockMarket_server.Pages
{
    public class MakeUpdateModel : PageModel
    {

        private readonly sqlConnection _db;

        public MakeUpdateModel(sqlConnection db)
        {
            _db = db;
        }

        public double Id { get; set; }
        
        public string Trade { get; set; }
        public double High { get; set; }
        public double Low { get; set; }
        public double Open { get; set; }
        public double Close { get; set; }
        public double Volume { get; set; }

        public IEnumerable<sqlModel> DataList { get; set; }
        public int GetSuccess { get; set; }

        public void OnGet(int Id, string trade_code, double high, double low, double open, double close, double volume)
        {
                       
            Trade = trade_code;
            High = high;
            Low = low;
            Open = open;
            Close = close;
            Volume = volume;

            int cmnd = _db.Database.ExecuteSqlRaw("UPDATE dbo.StockData SET date={0},trade_code={1},high={2},low={3},[open]={4},[close]={5},volume={6} WHERE Id={7} ", DateTime.Now,Trade,High,Low,Open,Close,Volume, Id);

            if (cmnd > 0)
            {
                GetSuccess = 1;
            }
            else
            {
                GetSuccess = 0;
            }

            Redirect("/Index");

        }
    }
}
