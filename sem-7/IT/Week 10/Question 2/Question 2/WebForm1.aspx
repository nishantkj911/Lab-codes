<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AutoGenerateColumns="False" DataKeyNames="Id" 
                DataSourceID="SqlDataSource1" OnRowUpdating="GridView1_RowUpdating" PageSize="3">
                <RowStyle BackColor="MediumSeaGreen" ForeColor="DarkRed"/>
                <Columns>
                    <asp:CommandField ShowEditButton="true" />
                    <asp:BoundField DataField="Id" HeaderText="Id" ReadOnly="True" SortExpression="Id" />
                    <asp:TemplateField HeaderText="Name" SortExpression="First_Name">
                        <EditItemTemplate>
                            <div>
                                First Name: <asp:Label ID="Label3" runat="server" Text='<%# Bind("First_Name") %>'></asp:Label>
                            </div>
                            <div>
                                Last Name: <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Last_Name") %>'></asp:TextBox>
                            </div>
                        </EditItemTemplate>
                        <ItemTemplate>
                            <div>
                                First Name: <asp:Label ID="Label1" runat="server" Text='<%# Bind("First_Name") %>'></asp:Label>
                            </div>
                            <div>
                                Last Name: <asp:Label ID="Label2" runat="server" Text='<%# Bind("Last_Name") %>'></asp:Label>
                            </div>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:BoundField DataField="Book_Title" HeaderText="Book_Title" SortExpression="Book_Title" ReadOnly="true"/>
                    <asp:BoundField DataField="Genre" HeaderText="Genre" SortExpression="Genre" ReadOnly="true"/>
                    <asp:BoundField DataField="Copies_Sold" HeaderText="Copies_Sold" SortExpression="Copies_Sold" />
                </Columns>
            </asp:GridView>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=ExampleDatabase;Integrated Security=True" 
                ProviderName="System.Data.SqlClient" SelectCommand="SELECT * FROM [Authors]">
            </asp:SqlDataSource>
            <br />
            <br />
            <asp:Label ID="Label3" runat="server" Text=""></asp:Label>
        </div>
    </form>
</body>
</html>
