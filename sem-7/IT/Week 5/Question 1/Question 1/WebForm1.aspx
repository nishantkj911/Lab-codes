<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Car Manufacturers:&nbsp;&nbsp;&nbsp;
            <asp:DropDownList ID="carManufacturer" runat="server">
                <asp:ListItem>Mercedez</asp:ListItem>
                <asp:ListItem>BMW</asp:ListItem>
                <asp:ListItem>Bentley</asp:ListItem>
                <asp:ListItem>Ferarri</asp:ListItem>
            </asp:DropDownList>
            <br />
            Model Name:&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="modelNameTB" runat="server"></asp:TextBox>
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Show Details" />
        </div>
    </form>
</body>
</html>
