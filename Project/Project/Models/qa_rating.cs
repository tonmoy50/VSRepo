using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class qa_rating
    {
        
        public int qa_id { get; set; }
        public int u_id { get; set; }
        public int qa_ratng { get; set; }
    }

    public class qa_ratingDBContext : DbContext
    {
        public DbSet<qa_rating> Movies { get; set; }
    }

}