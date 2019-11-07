<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_4.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            Select a genre:&nbsp;&nbsp;&nbsp;
            <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True">
            </asp:DropDownList>
            <br />
            <br />
            Actors in Selected Genre:<br />
            <asp:ListBox ID="ListBox1" runat="server" AutoPostBack="True" DataTextField="name" DataSourceID="SqlDataSource1" DataValueField="Id"></asp:ListBox>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=ExampleDatabase;Integrated Security=True" ProviderName="System.Data.SqlClient" SelectCommand="SELECT [name], [Id] FROM [Actors] WHERE ([category] = @category)">
                <SelectParameters>
                    <asp:ControlParameter ControlID="DropDownList1" Name="category" PropertyName="SelectedValue" Type="String" />
                </SelectParameters>
            </asp:SqlDataSource>
            <br />
            <br />
            Details of Actors:<asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="Id" DataSourceID="SqlDataSource2" >
                <Columns>
                    <asp:BoundField DataField="Id" HeaderText="Id" ReadOnly="True" SortExpression="Id" />
                    <asp:BoundField DataField="name" HeaderText="name" SortExpression="name" />
                    <asp:BoundField DataField="age" HeaderText="age" SortExpression="age" />
                    <asp:BoundField DataField="category" HeaderText="category" SortExpression="category" />
                </Columns>
            </asp:GridView>
            <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=ExampleDatabase;Integrated Security=True" ProviderName="System.Data.SqlClient" SelectCommand="SELECT * FROM [Actors] WHERE ([Id] = @Id)">
                <SelectParameters>
                    <asp:ControlParameter ControlID="ListBox1" Name="Id" PropertyName="SelectedValue" Type="String" />
                </SelectParameters>
            </asp:SqlDataSource>
        </div>
    </form>
</body>
</html>
