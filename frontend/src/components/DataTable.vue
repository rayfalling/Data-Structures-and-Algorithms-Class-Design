<!--suppress ALL -->
<template>
    <div>
        <el-row :gutter="20" type="flex" align="middle">
            <el-col :span="6">
                <h3>
                    Advertisement List
                </h3>
            </el-col>
            <el-col :span="8" :offset="14">
                <el-button-group>
                    <el-button type="primary" icon="el-icon-plus">添加</el-button>
                    <el-button type="primary" icon="el-icon-close" @click="Logout">注销</el-button>
                </el-button-group>
            </el-col>
        </el-row>
        <el-table :data="tableData" style="width: 100%">
            <el-table-column fixed prop="name" label="名称" sortable="custom" width="150">
            </el-table-column>
            <el-table-column prop="poster" label="发布者" sortable="custom" width="150">
            </el-table-column>
            <el-table-column prop="post_date" label="发布日期" sortable="custom" width="180">
            </el-table-column>
            <el-table-column prop="close_date" label="结束日期" sortable="custom" width="180">
            </el-table-column>
            <el-table-column prop="quantity" label="数量" sortable="custom" width="120">
            </el-table-column>
            <el-table-column prop="description" label="描述" width="220">
            </el-table-column>
            <el-table-column fixed="right" label="操作" width="120">
                <template slot-scope="scope">
                    <el-button @click.native.prevent="GoBid(scope.$index, tableData)" type="text" size="small">
                        投标
                    </el-button>
                </template>
            </el-table-column>
        </el-table>
    </div>
</template>

<script>
    export default {
        name: "DataTable",
        data() {
            return {tableData: []}
        },
        methods: {
            Logout() {
                this.axios.post("/api/logout").then(response => {
                    if ("status" in response.data && response.data.status) {
                        this.$message({
                            showClose: true,
                            message: '注销成功',
                            type: 'success'
                        });
                        this.$store.commit("changeLoginStatus", true)
                        this.$nextTick(() => {
                            this.$router.push("/exercise/login")
                        })
                    } else {
                        this.$message({
                            showClose: true,
                            message: '注销失败',
                            type: 'error'
                        });
                        this.login.email = "";
                        this.login.password = "";
                    }
                }).catch(error => console.log(error))
            }
        },
        mounted() {
            if (!this.$store.state.loginStatus) {
                this.$message({
                    showClose: true,
                    message: '你还没有登录= =',
                    type: 'error'
                });
                this.$router.push('/exercise/login')
            }
        }
    }
</script>

<style scoped>

</style>