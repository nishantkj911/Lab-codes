using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Xml.Linq;
using System.Xml;
using System.Text;

namespace Question_3
{
    public class ExampleClass
    {
        public static void WriteXMLDocument()
        {
            XDocument doc = new XDocument(
                new XComment("This is an auto generated XML file."),
                new XElement("Cars",
                    new XElement("Detail",
                        new XElement("Name", "I20"),
                        new XElement("Make", "Hyundai"),
                        new XElement("Price", "700000")),
                    new XElement("Detail",
                        new XElement("Name", "Alto"),
                        new XElement("Make", "Maruti Suzuki"),
                        new XElement("Price", "300000"))));

            XmlTextWriter textWriter = new XmlTextWriter(HttpRuntime.AppDomainAppPath + "XMLFile2.xml", Encoding.UTF8);
            doc.WriteTo(textWriter);
            textWriter.Close();
        }
    }
}