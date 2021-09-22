using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class user_rating
    {
        public int u_id { get; set; }
        public int u_rating { get; set; }
        public string user_tag { get; set; }
    }

    public class user_ratingDBContext : DbContext
    {
        public DbSet<user_rating> project { get; set; }
    }
}