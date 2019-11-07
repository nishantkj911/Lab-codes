<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div style="height:auto; width:25%">
                <div style="float:left; text-align:center">
                    Packages:&nbsp;&nbsp;&nbsp;
                </div>
                <div style="float:right">
                    <asp:ListBox ID="ListBox1" runat="server" DataSourceID="SqlDataSource1" DataTextField="Place" DataValueField="PlaceId"></asp:ListBox>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=ExampleDatabase;Integrated Security=True" 
                        ProviderName="System.Data.SqlClient" SelectCommand="SELECT [PlaceId], [Place] FROM [Packages]"></asp:SqlDataSource>
                </div>
            </div>
            <div>
                <asp:Button ID="Button1" runat="server" Text="Get Details" OnClick="Button1_Click" />
            </div>
        </div>
    </form>
</body>
</html>
