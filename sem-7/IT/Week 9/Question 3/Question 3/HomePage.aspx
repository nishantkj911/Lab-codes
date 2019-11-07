<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="HomePage.aspx.cs" Inherits="Question_3.HomePage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            State:&nbsp;&nbsp;&nbsp;
            <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="true">
            </asp:DropDownList> 
            <br />
            <br />
            Cities:&nbsp;&nbsp;&nbsp;
            <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource1" DataTextField="CityName">
            </asp:DropDownList>
            <br />
            <div>
                <asp:SqlDataSource ID="SqlDataSource1" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=ExampleDatabase;Integrated Security=True" runat="server" SelectCommand="Select CityName from City where StateID = @id">
                    <SelectParameters>
                        <asp:ControlParameter ControlID="DropDownList1" PropertyName="SelectedValue" Name="id" />
                    </SelectParameters>
                </asp:SqlDataSource>
            </div>
        </div>
    </form>
</body>
</html>
