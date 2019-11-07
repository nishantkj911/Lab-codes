<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="ExampleValidation.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Username:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox1" Display="Dynamic" ErrorMessage="Enter a username" >*</asp:RequiredFieldValidator>
            <br />
            Password:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox>
            <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="TextBox2" ErrorMessage="Enter correct password" >*</asp:RequiredFieldValidator>
            <br />
            Display Name:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox3" runat="server" ToolTip="Minimum length is 10, first letter in UpperCase "></asp:TextBox>
            <asp:CustomValidator ID="CustomValidator1" runat="server" ControlToValidate="TextBox3" ErrorMessage="Enter a valid Display name" OnServerValidate="CustomValidator1_ServerValidate" ValidateEmptyText="True" >Criteria are not satisfied</asp:CustomValidator>
            <br />
            <br />
            <asp:Button ID="Button1" runat="server" Text="Button"/>
            <br />
            <p id="para" runat="server"></p>
&nbsp;<asp:ValidationSummary ID="ValidationSummary1" runat="server" DisplayMode="List" EnableTheming="True" ShowMessageBox="True"  />
        </div>
    </form>
</body>
</html>
