<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div>
                <div>
                    Fruits: <asp:CheckBoxList ID="CheckBoxList1" runat="server"></asp:CheckBoxList>
                </div>
                <div>
                    Ice Cream Flavour: <asp:RadioButtonList ID="RadioButtonList1" runat="server"></asp:RadioButtonList>
                </div>
            </div>
            <div>
                <div>
                    <asp:Button ID="Button1" runat="server" Text="Generate Milkshake" OnClick="Button1_Click" />
                </div>
                <div>
                    <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
                </div>
            </div>
        </div>
    </form>
</body>
</html>
