using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;
using Microsoft.EntityFrameworkCore;


namespace StockMarket_server.Model
{
    
    public class sqlModel
    {
        [Key]
        public double Id { get; set; }
        public DateTime Date { get; set; }
        public string Trade_Code { get; set; }
        public double High { get; set; }
        public double Low { get; set; }
        public double Open { get; set; }
        public double Close { get; set; }
        public double Volume { get; set; }



    }

    
}
