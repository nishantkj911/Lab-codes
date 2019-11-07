<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div dir="ltr">
            Employee ID:&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:DropDownList ID="DropDownList1" runat="server" >
                <asp:ListItem>10025123</asp:ListItem>
                <asp:ListItem>10025289</asp:ListItem>
                <asp:ListItem>10023245</asp:ListItem>
                <asp:ListItem>20047853</asp:ListItem>
                <asp:ListItem>20054633</asp:ListItem>
            </asp:DropDownList>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Button ID="Button1" runat="server" Text="Show Image" Width="121px" OnClick="Button1_Click" />
            <br />
            <asp:Image ID="Image1" runat="server"/>
            <br />
            Name of the employee:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="employeeNameTB" runat="server"></asp:TextBox>
            <br />
            Date of Joining:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="DateOfJoiningTB" runat="server"></asp:TextBox>
            <br />
            <asp:Button ID="eligibilityCheckButton" runat="server" Text="Am I eligibile for Promotion" OnClick="eligibilityCheckButton_Click" />
            <br />
            <br />
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
        </div>
    </form>
</body>
</html>
