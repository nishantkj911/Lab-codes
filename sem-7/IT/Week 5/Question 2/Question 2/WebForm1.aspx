<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Name:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="nameTB" runat="server"></asp:TextBox>
            <br />
            Roll No:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="rollNoTB" runat="server"></asp:TextBox>
            <br />
            Subject:&nbsp;&nbsp;&nbsp;
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>Maths</asp:ListItem>
                <asp:ListItem>Physics</asp:ListItem>
                <asp:ListItem>Chemistry</asp:ListItem>
                <asp:ListItem>Biology</asp:ListItem>
                <asp:ListItem>Computer Science</asp:ListItem>
                <asp:ListItem>2nd Language</asp:ListItem>
            </asp:DropDownList>
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" Text="Show Details" OnClick="Button1_Click"/>
        </div>
    </form>
</body>
</html>
