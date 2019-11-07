<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="Question_2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div>
                <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="PackageId" DataSourceID="SqlDataSource1">
                    <Columns>
                        <asp:BoundField DataField="Place" HeaderText="Place" SortExpression="Place" />
                        <asp:BoundField DataField="Days" HeaderText="Days" SortExpression="Days" />
                        <asp:BoundField DataField="Cost" HeaderText="Cost" SortExpression="Cost" />
                    </Columns>
                </asp:GridView>
                <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ExampleDatabaseConnectionString %>" SelectCommand="SELECT * FROM [Packages] WHERE ([PlaceID] = @PlaceId)">
                    <SelectParameters>
                        <asp:QueryStringParameter Name="PlaceId" QueryStringField="q" />
                    </SelectParameters>
                </asp:SqlDataSource>
            </div>
        </div>
    </form>
</body>
</html>
