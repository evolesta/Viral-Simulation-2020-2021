using System;
using System.IO;
using System.Xml.Serialization;
using HtmlAgilityPack;
using NUnit.Framework;
using NUnit.Framework.Internal;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium.Firefox;

namespace ViralSimulation.SeleniumTests
{
    public class Class1
    {

        [Test]
        public void Failing_Test()
        {
            Assert.Fail();
        }

        [Test]
        public void Body_Should_Contain_Correct_Heading()
        {
            var document = new HtmlDocument();
            //For local debugging:
            //var stream = File.OpenText(@"C:\Data\index.html");
            var stream = File.OpenText("/home/src/viralsim/index.html");
            document.Load(stream);

            var body = document.DocumentNode.ChildNodes.FindFirst("body");
            var titleElement = body.ChildNodes.FindFirst("h1");
            //Assert.Greater(document.DocumentNode.ChildNodes.Count, 0);
            Assert.AreEqual("Coronavirus Simulatie", titleElement.InnerText);
        }
    }
}
