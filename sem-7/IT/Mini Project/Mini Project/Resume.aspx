<%@ Page Title="" Language="C#" MasterPageFile="~/PlacementMaster.Master" AutoEventWireup="true" CodeBehind="Resume.aspx.cs" Inherits="Mini_Project.Resume" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headerContentPlaceHolder" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div class="bg-light">
        <div class="h2 text-center">Resume Info</div>
    </div>
    <div class="container">
        <div class="table">
            <div class="row my-4 ml-4">
                <div class="h3 col-3 text-center">
                    Skills
                </div>
                <div class="col-9">
                    <asp:GridView CssClass="table-bordered" ShowFooter="True" ShowHeaderWhenEmpty="true" ID="SkillsGridView" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1" OnRowUpdating="SkillsGridView_RowUpdating" OnRowEditing="SkillsGridView_RowEditing" OnRowDeleting="SkillsGridView_RowDeleting">
                        <Columns>
                            <asp:TemplateField ShowHeader="False">
                                <ItemTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="False" CommandName="Delete" Text="Delete"></asp:LinkButton>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CommandName="Insert" CommandArgument="Insert" OnClick="LinkButton1_Click">Insert</asp:LinkButton>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="Skill" SortExpression="Skill">
                                <EditItemTemplate>
                                    <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Skill") %>'></asp:TextBox>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Bind("Skill") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                        </Columns>
                    </asp:GridView>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                        ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
                        SelectCommand="SELECT [Skill] FROM [Skills] WHERE ([Regno] = @Regno)">
                        <SelectParameters>
                            <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                </div>
            </div>
            
            <div class="row my-4 ml-4">
                <div class="h3 col-3 text-center">
                    Course Certifications
                </div>
                <div class="col-9">
                    <asp:GridView CssClass="table-bordered" ShowFooter="True" ShowHeaderWhenEmpty="true" ID="CourseCertificationGridView" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource2" DataKeyNames="Regno,Title" >
                        <Columns>
                            <asp:TemplateField ShowHeader="False">
                                <EditItemTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="True" CommandName="Update" Text="Update"></asp:LinkButton>
                                    &nbsp;<asp:LinkButton ID="LinkButton2" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel"></asp:LinkButton>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="False" CommandName="Edit" Text="Edit"></asp:LinkButton>
                                    &nbsp;<asp:LinkButton ID="LinkButton2" runat="server" CausesValidation="False" CommandName="Delete" Text="Delete"></asp:LinkButton>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:LinkButton ID="InsertCC" runat="server" CommandName="Insert" CommandArgument="Insert" OnClick="InsertCC_Click">Insert</asp:LinkButton>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="Author" SortExpression="Author">
                                <EditItemTemplate>
                                    <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Author") %>'></asp:TextBox>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Bind("Author") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="InsertCCAuthorTB" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="Title" SortExpression="Title">
                                <EditItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Eval("Title") %>'></asp:Label>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label2" runat="server" Text='<%# Bind("Title") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="InsertCCTitleTB" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                        </Columns>
                    </asp:GridView>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
                        ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
                        SelectCommand="SELECT * FROM [CourseCertifications] WHERE ([Regno] = @Regno)" 
                        DeleteCommand="DELETE FROM [CourseCertifications] WHERE [Regno] = @Regno AND [Title] = @Title" 
                        InsertCommand="INSERT INTO [CourseCertifications] ([Regno], [Author], [Title]) VALUES (@Regno, @Author, @Title)" 
                        UpdateCommand="UPDATE [CourseCertifications] SET [Author] = @Author WHERE [Regno] = @Regno AND [Title] = @Title">
                        <DeleteParameters>
                            <asp:SessionParameter SessionField="Regno" Type="Int32" Name="Regno" />
                            <asp:Parameter Name="Title" Type="String" />
                        </DeleteParameters>
                        <SelectParameters>
                            <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
                        </SelectParameters>
                        <UpdateParameters>
                            <asp:SessionParameter SessionField="Regno" Type="Int32" Name="Regno" />
                            <asp:Parameter Name="Author" Type="String" />
                            <asp:Parameter Name="Title" Type="String" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                </div>
            </div>
            
            <div class="row my-4 ml-4">
                <div class="h3 col-3 text-center">
                    Professional Experience
                </div>
                <div class="col-9">
                    <asp:GridView CssClass="table-bordered" ShowFooter="True" ID="ProfessionalExperienceGridView" ShowHeaderWhenEmpty="true" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource3" DataKeyNames="Regno,JobTitle" OnRowUpdating="ProfessionalExperienceGridView_RowUpdating" >
                        <Columns>
                            <asp:TemplateField ShowHeader="False">
                                <ItemTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="False" CommandName="Delete" Text="Delete"></asp:LinkButton>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:LinkButton ID="InsertPELB" runat="server" CommandName="Insert" CommandArgument="Insert" OnClick="InsertPELB_Click">Insert</asp:LinkButton>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="JobTitle" SortExpression="JobTitle">
                                <EditItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Eval("JobTitle") %>'></asp:Label>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Bind("JobTitle") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="InsertPEJTTB" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="Job Description" SortExpression="Job Description">
                                <EditItemTemplate>
                                    <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("[Job Description]") %>'></asp:TextBox>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label2" runat="server" Text='<%# Bind("[Job Description]") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="InsertPEJDTB" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                        </Columns>
                    </asp:GridView>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" 
                        ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
                        SelectCommand="SELECT * FROM [ProfessionalExperience] WHERE ([Regno] = @Regno)" 
                        DeleteCommand="DELETE FROM [ProfessionalExperience] WHERE [Regno] = @Regno AND [JobTitle] = @JobTitle" 
                        InsertCommand="INSERT INTO [ProfessionalExperience] ([Regno], [JobTitle], [Job Description]) VALUES (@Regno, @JobTitle, @Job_Description)" 
                        UpdateCommand="UPDATE [ProfessionalExperience] SET [Job Description] = @Job_Description WHERE [Regno] = @Regno AND [JobTitle] = @JobTitle">
                        <DeleteParameters>
                            <asp:SessionParameter SessionField="Regno" Type="Int32" Name="Regno" />
                            <asp:Parameter Name="JobTitle" Type="String" />
                        </DeleteParameters>
                        <SelectParameters>
                            <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
                        </SelectParameters>
                        <UpdateParameters>
                            <asp:Parameter Name="Job_Description" Type="String" />
                            <asp:Parameter Name="JobTitle" Type="String" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                </div>
            </div>
            
            <div class="row my-1 ml-1">
                <div class="h3 col-3 text-center">
                    Recommendations
                </div>
                <div class="col-9">
                    <asp:GridView CssClass="table-bordered" ShowHeaderWhenEmpty="true" ShowFooter="True" ID="RecommendationsGridView" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource4" DataKeyNames="Regno,TeacherName">
                        <Columns>
                            <asp:TemplateField ShowHeader="False">
                                <EditItemTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="True" CommandName="Update" Text="Update"></asp:LinkButton>
                                    &nbsp;<asp:LinkButton ID="LinkButton2" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel"></asp:LinkButton>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:LinkButton ID="LinkButton1" runat="server" CausesValidation="False" CommandName="Edit" Text="Edit"></asp:LinkButton>
                                    &nbsp;<asp:LinkButton ID="LinkButton2" runat="server" CausesValidation="False" CommandName="Delete" Text="Delete"></asp:LinkButton>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:LinkButton ID="InsertRecLB" runat="server" OnClick="InsertRecLB_Click">Insert</asp:LinkButton>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="TeacherName" SortExpression="TeacherName">
                                <EditItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Eval("TeacherName") %>'></asp:Label>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label1" runat="server" Text='<%# Bind("TeacherName") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="InsertRecTNTB" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                            <asp:TemplateField HeaderText="Remarks" SortExpression="Remarks">
                                <EditItemTemplate>
                                    <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Remarks") %>'></asp:TextBox>
                                </EditItemTemplate>
                                <ItemTemplate>
                                    <asp:Label ID="Label2" runat="server" Text='<%# Bind("Remarks") %>'></asp:Label>
                                </ItemTemplate>
                                <FooterTemplate>
                                    <asp:TextBox ID="InsertRecRemTB" runat="server"></asp:TextBox>
                                </FooterTemplate>
                            </asp:TemplateField>
                        </Columns>
                    </asp:GridView>
                    <asp:SqlDataSource ID="SqlDataSource4" runat="server" 
                        ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
                        SelectCommand="SELECT * FROM [Recommendations] WHERE ([Regno] = @Regno)" 
                        DeleteCommand="DELETE FROM [Recommendations] WHERE [Regno] = @Regno AND [TeacherName] = @TeacherName" 
                        InsertCommand="INSERT INTO [Recommendations] ([Regno], [TeacherName], [Remarks]) VALUES (@Regno, @TeacherName, @Remarks)" 
                        UpdateCommand="UPDATE [Recommendations] SET [Remarks] = @Remarks WHERE [Regno] = @Regno AND [TeacherName] = @TeacherName">
                        <DeleteParameters>
                            <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
                            <asp:Parameter Name="TeacherName" Type="String" />
                        </DeleteParameters>
                        <SelectParameters>
                            <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
                        </SelectParameters>
                        <UpdateParameters>
                            <asp:Parameter Name="Remarks" Type="String" />
                            <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
                            <asp:Parameter Name="TeacherName" Type="String" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                </div>
            </div>
        </div>
    </div>
</asp:Content>
