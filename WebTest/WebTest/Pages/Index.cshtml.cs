using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;
using WebTest.Models;
using WebTest.Services;

namespace WebTest.Pages
{
    public class IndexModel : PageModel
    {
        private readonly ILogger<IndexModel> _logger;
        public JsonServiceProducts ProductService;
        public IEnumerable<Products> Productss { get; private set; }

        public IndexModel(
            ILogger<IndexModel> logger, 
            JsonServiceProducts productService)
        {
            _logger = logger;
            ProductService = productService;
        }

        public void OnGet()
        {
            Productss = ProductService.GetProducts();
        }
    }
}
