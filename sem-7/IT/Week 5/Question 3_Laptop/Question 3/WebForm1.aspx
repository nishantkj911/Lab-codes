<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Please Enter your name:
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <asp:HiddenField ID="NameHiddenField" runat="server" />
            <br />
            Please Select your products:
            <asp:ListBox ID="ListBox1" runat="server">
                <asp:ListItem Value="3000">Keyboard</asp:ListItem>
                <asp:ListItem Value="700">Mouse</asp:ListItem>
                <asp:ListItem Value="1200">Speakers</asp:ListItem>
                <asp:ListItem Value="5000">Hard Drive</asp:ListItem>
            </asp:ListBox>
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Continue Shopping" PostBackUrl="~/WebForm2.aspx"/>
        </div>
    </form>
</body>
</html>
