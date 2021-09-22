using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Routing;
using Microsoft.EntityFrameworkCore;
using StockMarket_server.Model;

namespace StockMarket_server.Pages
{
    public class UpdateDataModel : PageModel
    {
        private readonly sqlConnection _db;

        public UpdateDataModel(sqlConnection db)
        {
            _db = db;
        }

        public IEnumerable<sqlModel> GetIdData { get; set; }
        public int Selected { get; set; }

        public void OnGet(int Id)
        {
            Selected = Id;
            GetIdData = _db.StockData.FromSqlRaw("SELECT * FROM dbo.StockData WHERE Id={0}", Id);
            
        }
    }
}
