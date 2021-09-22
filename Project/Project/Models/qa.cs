using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class qa
    {
        public int qa_id { get; set; }
        public int u_id { get; set; }
        public string qa_title { get; set; }
        public string qa_body { get; set; }
    }

    public class qaDBContext : DbContext
    {
        public DbSet<qa> Movies { get; set; }
    }
}