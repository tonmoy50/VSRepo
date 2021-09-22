
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;


namespace Project.Models
{
    public class video
    {
        public int vid_id { get; set; }
        public int u_id { get; set; }
        public string vid_title { get; set; }
        public string vid_path { get; set; }
    }

     public class ProjectDBContext : DbContext
    {
        public DbSet<video> project { get; set; }
    }
}