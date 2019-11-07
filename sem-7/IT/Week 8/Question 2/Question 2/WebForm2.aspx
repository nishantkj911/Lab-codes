<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="Question_2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
             <asp:DropDownList ID="DropDownList1" runat="server">
            </asp:DropDownList>
            <br />
            <br />
            <asp:ListBox ID="ListBox1" runat="server"></asp:ListBox>
            <br />
            <br />
            <asp:TextBox ID="TextBox1" runat="server" Height="50px" Rows="4"></asp:TextBox>
            <asp:Label ID="Label1" runat="server" Text="Label">Wassup <%# Message %> </asp:Label>
        </div>
    </form>
</body>
</html>
