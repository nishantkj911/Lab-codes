<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="ExampleApplication1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
<style>
    #rbClass {
        list-style: none;
        padding: 0;
        margin: 0
    }
    #rbClass.horizontal li {
        display: inline
    }

    .newClass {
        white-space: pre-wrap;
    }
</style>
    <form id="form1" runat="server">
        <div style="width: 649px; background-color: aliceblue; font-family: Cambria" runat="server" id="someDiv">
            Name:&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="TextBox1" runat="server" CssClass="newClass"></asp:TextBox>
&nbsp;
            &nbsp;
            <br />
            <br />
            Gender:
            <asp:RadioButton ID="Male" runat="server" GroupName="gender"/>
        &nbsp;Male
            <asp:RadioButton ID="Female" runat="server" GroupName="gender"/>
            &nbsp;Female
            <asp:RadioButton ID="Other" runat="server" GroupName="gender"/>&nbsp;Other<br />
            <br />
            Branch:<asp:RadioButtonList ID="RadioButtonList1" runat="server" Width="232px" RepeatDirection="Horizontal">
                <asp:ListItem>CSE</asp:ListItem>
                <asp:ListItem>IT</asp:ListItem>
                <asp:ListItem>CCE</asp:ListItem>
            </asp:RadioButtonList>
            <asp:Label ID="Label1" runat="server" Text="Something"></asp:Label>
&nbsp;&nbsp;<asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem Value="flavour">ice cream</asp:ListItem>
            </asp:DropDownList>
            <p id="myPara" runat="server"></p>
            <asp:Button ID="Submit" runat="server" Text="Submit" OnClick="Submit_Click" />
        </div>
    </form>
</body>
</html>
