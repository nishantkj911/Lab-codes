<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 50%;
            align-content: center;
        }
        .auto-style2 {
            width: 62%;
            align-content: center;
        }
        .auto-style3 {
            width: 62%;
            align-content: center;
            height: 49px;
        }
        .auto-style4 {
            align-content: center;
            height: 49px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Student House Presidential Election</h1>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">Choose a candidate</td>
                    <td>
                        <asp:DropDownList ID="DropDownList1" runat="server">
                        </asp:DropDownList>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ErrorMessage="Select someone for candidate!" ControlToValidate="DropDownList1"></asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">House</td>
                    <td>
                        <asp:RadioButtonList ID="RadioButtonList1" runat="server">
                            <asp:ListItem>Gryffindor</asp:ListItem>
                            <asp:ListItem>Ravenclaw</asp:ListItem>
                            <asp:ListItem>Slytherin</asp:ListItem>
                            <asp:ListItem>Hufflepuff</asp:ListItem>
                        </asp:RadioButtonList>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ErrorMessage="Select a House!" ControlToValidate="RadioButtonList1" Font-Bold="True" ForeColor="Red"></asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style3">Class</td>
                    <td class="auto-style4">
                        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                        <asp:RangeValidator ID="RangeValidator1" runat="server" ErrorMessage="Classes only between 6 and 12" ControlToValidate="TextBox1" MaximumValue="12" MinimumValue="6" Type="Integer" Font-Bold="True" ForeColor="Red"></asp:RangeValidator>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ErrorMessage="Class field is Mandatory" ControlToValidate="TextBox1" Font-Bold="True" ForeColor="Red"></asp:RequiredFieldValidator>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">Parent Contact No. (+91)</td>
                    <td>
                        <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
                        <asp:CustomValidator ID="CustomValidator1" runat="server" ErrorMessage="Invalid Contact no. You can't get away with this..." ControlToValidate="TextBox3" OnServerValidate="CustomValidator1_ServerValidate" Font-Bold="True" ForeColor="Red"></asp:CustomValidator>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">Email ID</td>
                    <td>
                        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                        <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ErrorMessage="Enter a proper format for email ID" ControlToValidate="TextBox2" SetFocusOnError="True" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*" Font-Bold="True" ForeColor="Red"></asp:RegularExpressionValidator>
                        <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" ErrorMessage="Email ID is mandatory" ControlToValidate="TextBox2" Font-Bold="True" ForeColor="Red"></asp:RequiredFieldValidator>
                    </td>
                </tr>
            </table>
            <asp:ValidationSummary ID="ValidationSummary1" runat="server" ShowMessageBox="True" Visible="False" />
            <br />
            <asp:Button ID="Button1" runat="server" Text="Submit" OnClick="Button1_Click" />

            <br />

            <p id="para" runat="server"></p>
        </div>
    </form>
</body>
</html>
