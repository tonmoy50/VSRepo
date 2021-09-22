using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class user
    {
        public int u_id { get; set; }
        public string username { get; set; }
        public string email { get; set; }

        public string password { get; set; }

        public int admin_check { get; set; }
           
        public int ban { get; set; }
        

    }
    public class userDBContext : DbContext
    {
        public DbSet<user> Movies { get; set; }
    }
}