<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="W8_Q4.WebForm1" %>


<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:TextBox runat="server" ID="name" ToolTip="Enter name"></asp:TextBox>
             Enter Company to know details<br />

            <br />
            <asp:TextBox runat="server" ID="company" ToolTip="Enter company name" OnTextChanged="company_TextChanged"></asp:TextBox>
            
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />

            <br />

            <asp:Button ID="Give" runat="server" Text="Give" onclick="Give_Click"/>
            <br />
            <br />
            <asp:TextBox runat="server" ID="salary" ToolTip="Enter salary"></asp:TextBox>
            
        
            <asp:Label ID="Label1" runat="server"></asp:Label>
<br />
            <br />
            <asp:Label ID="Label2" runat="server" Text="Label"></asp:Label>
            
            
        </div>
        <p>
            <asp:Button ID="Insert" runat="server" Text="Insert" OnClick="Insert_Click" />
        </p>
        <p>
            </p>
        <p>
            </p>
        <p>
            </p>
    </form>
</body>
</html>