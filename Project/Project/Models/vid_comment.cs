using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class vid_comment
    {
        public int c_id { get; set; }
        public int u_id { get; set; }
        public int vid_id { get; set; }
        public string comment { get; set; }
    }
    public class vid_commentDBContext : DbContext
    {
        public DbSet<vid_comment> project { get; set; }
    }
}