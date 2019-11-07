<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>
        E-Card Generator
    </title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div>
                Background Color:
                <asp:DropDownList ID="bgColorDropDownList" runat="server">
                </asp:DropDownList>
                <br />
                Font Type:&nbsp;&nbsp;&nbsp;
                <asp:DropDownList ID="fontStyleDropDownList" runat="server">
                </asp:DropDownList>
                <br />
                Font Size:&nbsp;&nbsp;&nbsp;
                <asp:DropDownList ID="fontSizeDropDownList" runat="server">
                </asp:DropDownList>
                <br />
                Image:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <asp:FileUpload ID="FileUpload1" runat="server" />
                <br />
                Input Message:
                <asp:TextBox ID="TextBox1" runat="server" Rows="5"></asp:TextBox>
                <br />
                <br />
                <asp:Button ID="Button1" runat="server" Text="Generate E-Card" OnClick="Button1_Click" />
                <br />
            </div>
            <div>

            </div>
        </div>
    </form>
</body>
</html>
