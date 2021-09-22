using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WebTest.Models;
using WebTest.Services;

namespace WebTest.Controllers
{
    [ApiController]
    [Route("[controller]")]
    
    public class ProductsController : ControllerBase
    {
        public ProductsController(JsonServiceProducts productService)
        {
            this.ProductService = productService;
        }

        JsonServiceProducts ProductService { get; }

        [HttpGet]

        public IEnumerable<Products> Get()
        {
            return ProductService.GetProducts();
        }

        [Route("Rate")]
        [HttpGet]
        public ActionResult Get(
            [FromQuery] string productId, 
            [FromQuery] int ratings)
        {
            ProductService.AddRating(productId, ratings);
            return Ok();
        }
    }
}
