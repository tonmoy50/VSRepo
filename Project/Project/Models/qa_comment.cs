using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class qa_comment
    {
        public int c_id { get; set; }
        public int u_id { get; set; }
        public int qa_id { get; set; }
        public string comment { get; set; }
    }

    public class qa_commentDBContext : DbContext
    {
        public DbSet<qa_comment> Movies { get; set; }
    }
}