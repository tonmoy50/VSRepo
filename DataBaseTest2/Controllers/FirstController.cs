﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

using System.Data.SqlClient;

namespace DataBaseTest2.Controllers
{
    public class FirstController : Controller
    {

        

        


        public IActionResult Index()
        {
            

            return View();
        }
    }
}
