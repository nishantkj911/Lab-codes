<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_1.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="name" DataSourceID="SqlDataSource1" OnRowDataBound="GridView1_RowDataBound" AllowSorting="True">
                <Columns>
                    <asp:TemplateField AccessibleHeaderText="Accessible Header Text" HeaderText="Header Text" SortExpression="Name" >
                        <ItemTemplate>
                            <div>
                                <div style="float:left">
                                    <asp:Label ID="HeaderLinkButton" runat="server" Text='<%# Eval("Name") %>' ></asp:Label>
                                </div>
                                <div style="float:right">
                                    <asp:Label ID="Label2" runat="server" Text='<%# Eval("Age", "{0}") %>'></asp:Label>
                                </div>
                            </div>
                        </ItemTemplate>
                        <HeaderStyle Wrap="True"></HeaderStyle>
                        <HeaderTemplate>
                            <div>
                                <asp:LinkButton ID="HeaderLinkButton" CommandName="Sort" CommandArgument="Designation" Text="Staff Details" runat="server"></asp:LinkButton>
                            </div>
                            <div>
                                <div style="float:left">
                                    <u>Name</u>
                                </div>
                                <div style="float:right">
                                    <u>Age</u>
                                </div>
                            </div>
                        </HeaderTemplate>
                    </asp:TemplateField>
                    <asp:BoundField DataField="Designation" HeaderText="Designation" SortExpression="Designation" />
                    <asp:BoundField DataField="Salary" HeaderText="Salary" SortExpression="Salary" />
                </Columns> 
                <EditRowStyle />
            </asp:GridView>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=ExampleDatabase;Integrated Security=True" 
                ProviderName="System.Data.SqlClient" SelectCommand="SELECT * FROM [Staff]"></asp:SqlDataSource>
        </div>
    </form>
</body>
</html>
