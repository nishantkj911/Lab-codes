<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="SessionMgmnt.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div id="div1" runat="server">
            <asp:Button ID="Button1" runat="server" Text="Click Me!!" OnClick="Button1_Click" />
            &nbsp;<asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Go to next site" PostBackUrl="~/WebForm2.aspx"/>
            <br />
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            <asp:hiddenfield runat="server" ID="HiddenField1"></asp:hiddenfield>
            <p runat="server" id="para"></p>
        </div>
    </form>
</body>
</html>

