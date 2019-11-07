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
                Background Color:&nbsp;&nbsp;&nbsp;
                <asp:TextBox ID="TextBox2" runat="server" Width="20px"></asp:TextBox>
&nbsp;<asp:TextBox ID="TextBox3" runat="server" Width="20px"></asp:TextBox>
&nbsp;<asp:TextBox ID="TextBox4" runat="server" Width="20px"></asp:TextBox>
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
                <asp:FileUpload ID="FileUpload1" runat="server" accept=".jpg, .jpeg, .png, .gif"/>
                <br />
                Input Message:
                <asp:TextBox ID="TextBox1" runat="server" Rows="5"></asp:TextBox>
                <br />
                <br />
                <asp:Button ID="Button1" runat="server" Text="Generate E-Card" OnClick="Button1_Click" />
                <br />
                <br />
                <asp:Panel ID="Panel1" runat="server" Width="50%">
                    <br />
                    <p id="div2Para" runat="server"></p>
                </asp:Panel>
            </div>
        </div>
    </form>
</body>
</html>
