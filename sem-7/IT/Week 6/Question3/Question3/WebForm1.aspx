<%@ Page Language="C#" AutoEventWireup="true" Theme="SkinA" CodeBehind="WebForm1.aspx.cs" Inherits="Question3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" />
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>SkinA</asp:ListItem>
                <asp:ListItem>SkinB</asp:ListItem>
            </asp:DropDownList>
        </div>
    </form>
</body>
</html>
