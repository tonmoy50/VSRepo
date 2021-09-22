using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;

namespace StockMarket_server.Model
{
    public class testClass
    {
        [Key]

        public int Id { get; set; }
        public string Name { get; set; }
        public string Age { get; set; }
    }
}
