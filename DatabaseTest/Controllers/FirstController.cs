using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using System.Data.SqlClient;

namespace DatabaseTest.Controllers
{
    public class FirstController : Controller
    {

        private readonly IConfiguration configuration;

        public FirstController(IConfiguration config)
        {
            this.configuration = config;
        }

        public object SQLConnection { get; private set; }

        public IActionResult Index()
        {
            string connectionstring = configuration.GetConnectionString("DefaultConnectionStrings");

            SqlConnection connection = new SqlConnection(connectionstring);

            return View();
        }
    }
}
