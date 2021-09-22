using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class vid_ratting
    {
        public int qa_id { get; set; }
        public int u_id { get; set; }
        public int vid_ratng { get; set; }
    }

    public class vid_rattingDBContext : DbContext
    {
        public DbSet<vid_ratting> project { get; set; }
    }
}