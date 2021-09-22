using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace Project.Models
{
    public class message
    {
        public int m_id { get; set; }
        public int s_id { get; set; }
        public int destination_id { get; set; }
        public string message_details { get; set; }
    }

    public class messageDBContext : DbContext
    {
        public DbSet<message> Project { get; set; }
    }
}