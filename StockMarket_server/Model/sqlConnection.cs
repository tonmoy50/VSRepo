using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;


namespace StockMarket_server.Model
{
    public class sqlConnection : DbContext
    {

        public sqlConnection(DbContextOptions<sqlConnection> options):base(options)
        {

        }

        public DbSet<sqlModel> StockData {get; set;}
    }


}
