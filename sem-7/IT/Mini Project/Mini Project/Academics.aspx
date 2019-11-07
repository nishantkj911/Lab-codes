<%@ Page Title="" Language="C#" MasterPageFile="~/PlacementMaster.Master" AutoEventWireup="true" CodeBehind="Academics.aspx.cs" Inherits="Mini_Project.Academics" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headerContentPlaceHolder" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div class="row bg-light">
        <div class="h2 col col-6" id="headerText" runat="server"></div>
        <div class="col col-6 h3">Academic Details</div>
    </div>
    <div>
        <asp:GridView ID="GridView1" AutoGenerateEditButton="true" CssClass="table table-bordered" ShowFooter="True" ShowHeaderWhenEmpty="True" runat="server" AutoGenerateColumns="False" DataKeyNames="Regno" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:TemplateField HeaderText="Registration No" SortExpression="Regno">
                    <EditItemTemplate>
                        <asp:Label ID="Label1" runat="server" Text='<%# Eval("Regno") %>'></asp:Label>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label10" runat="server" Text='<%# Bind("Regno") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:LinkButton ID="RegNoLinkButton" Text="Insert" runat="server" CommandName="Insert" OnClick="RegNoLinkButton_Click"></asp:LinkButton>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 1 GPA" SortExpression="Semester1GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox1" runat="server" Text='<%# Bind("Semester1GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label1" runat="server" Text='<%# Bind("Semester1GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem1TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 2 GPA" SortExpression="Semester2GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox2" runat="server" Text='<%# Bind("Semester2GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label2" runat="server" Text='<%# Bind("Semester2GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem2TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 3 GPA" SortExpression="Semester3GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox3" runat="server" Text='<%# Bind("Semester3GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label3" runat="server" Text='<%# Bind("Semester3GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem3TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 4 GPA" SortExpression="Semester4GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox4" runat="server" Text='<%# Bind("Semester4GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label4" runat="server" Text='<%# Bind("Semester4GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem4TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 5 GPA" SortExpression="Semester5GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox5" runat="server" Text='<%# Bind("Semester5GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label5" runat="server" Text='<%# Bind("Semester5GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem5TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 6 GPA" SortExpression="Semester6GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox6" runat="server" Text='<%# Bind("Semester6GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label6" runat="server" Text='<%# Bind("Semester6GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem6TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 7 GPA" SortExpression="Semester7GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox7" runat="server" Text='<%# Bind("Semester7GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label7" runat="server" Text='<%# Bind("Semester7GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem7TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Semester 8 GPA" SortExpression="Semester8GPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox8" runat="server" Text='<%# Bind("Semester8GPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label8" runat="server" Text='<%# Bind("Semester8GPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertSem8TB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="CGPA" SortExpression="CGPA">
                    <EditItemTemplate>
                        <asp:textbox CssClass="form-control" ID="TextBox9" runat="server" Text='<%# Bind("CGPA") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:Label ID="Label9" runat="server" Text='<%# Bind("CGPA") %>'></asp:Label>
                    </ItemTemplate>
                    <FooterTemplate>
                        <asp:textbox CssClass="form-control" ID="InsertCGPATB" runat="server"></asp:TextBox>
                    </FooterTemplate>
                </asp:TemplateField>
            </Columns>
            <EmptyDataTemplate>Please Click On the Insert Button</EmptyDataTemplate>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server"
            ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" 
            DeleteCommand="DELETE FROM [AcademicInfo] WHERE [Regno] = @Regno" 
            InsertCommand="INSERT INTO [AcademicInfo] ([Regno], [Semester1GPA], [Semester2GPA], [Semester3GPA], [Semester4GPA], [Semester5GPA], [Semester6GPA], [Semester7GPA], [Semester8GPA], [CGPA]) VALUES (@Regno, @Semester1GPA, @Semester2GPA, @Semester3GPA, @Semester4GPA, @Semester5GPA, @Semester6GPA, @Semester7GPA, @Semester8GPA, @CGPA)" 
            ProviderName="System.Data.SqlClient" 
            SelectCommand="SELECT * FROM [AcademicInfo] WHERE ([Regno] = @Regno)" UpdateCommand="UPDATE [AcademicInfo] SET [Semester1GPA] = @Semester1GPA, [Semester2GPA] = @Semester2GPA, [Semester3GPA] = @Semester3GPA, [Semester4GPA] = @Semester4GPA, [Semester5GPA] = @Semester5GPA, [Semester6GPA] = @Semester6GPA, [Semester7GPA] = @Semester7GPA, [Semester8GPA] = @Semester8GPA, [CGPA] = @CGPA WHERE [Regno] = @Regno">
            <DeleteParameters>
                <asp:Parameter Name="Regno" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" DefaultValue="160000000" />
            </InsertParameters>
            <SelectParameters>
                <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
            </SelectParameters>
            <UpdateParameters>
                <asp:Parameter Name="Semester1GPA" Type="Double" />
                <asp:Parameter Name="Semester2GPA" Type="Double" />
                <asp:Parameter Name="Semester3GPA" Type="Double" />
                <asp:Parameter Name="Semester4GPA" Type="Double" />
                <asp:Parameter Name="Semester5GPA" Type="Double" />
                <asp:Parameter Name="Semester6GPA" Type="Double" />
                <asp:Parameter Name="Semester7GPA" Type="Double" />
                <asp:Parameter Name="Semester8GPA" Type="Double" />
                <asp:Parameter Name="CGPA" Type="Double" />
                <asp:Parameter Name="Regno" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <br />

    </div>
</asp:Content>
