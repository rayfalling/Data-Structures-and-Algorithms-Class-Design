<!--suppress ALL -->
<template>
    <div>
        <el-row :gutter="20" type="flex" align="middle">
            <el-col :span="6">
                <h3>
                    Advertisement List
                </h3>
            </el-col>
            <el-col :span="18" :offset="4">
                <el-input placeholder="搜索" clearable v-model="filter_keyword" class="input-with-select">
                    <el-select class="el-select-width" v-model="sort_method" slot="prepend" clearable
                               placeholder="排序方式">
                        <el-option label="名称" value="name"></el-option>
                        <el-option label="发布者" value="poster"></el-option>
                        <el-option label="发布日期" value="post_date"></el-option>
                        <el-option label="结束日期" value="close_date"></el-option>
                        <el-option label="数量" value="quantity"></el-option>
                        <el-option label="投标价(升序)" value="bid_asc"></el-option>
                        <el-option label="投标价(降序)" value="bid_desc"></el-option>
                    </el-select>
                    <el-button slot="append" icon="el-icon-search"></el-button>
                </el-input>
                <el-button-group>
                    <el-button type="primary" icon="el-icon-plus">添加</el-button>
                    <el-button type="primary" icon="el-icon-close" @click="Logout">注销</el-button>
                </el-button-group>
            </el-col>
        </el-row>
        <el-table :data="tableData" style="width: 100%;">
            <el-table-column fixed prop="name" label="名称" width="150">
            </el-table-column>
            <el-table-column prop="poster" label="发布者" width="150">
            </el-table-column>
            <el-table-column prop="post_date" label="发布日期" width="180">
            </el-table-column>
            <el-table-column prop="close_date" label="结束日期" width="180">
            </el-table-column>
            <el-table-column prop="quantity" label="数量" width="120">
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
            return {
                tableData: [],
                sort_method: "",
                filter_keyword: ""
            }
        },
        methods: {
            async Logout() {
                let response = await this.axios.post("/api/logout")
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
            },
            async RequestList() {
                let response = await this.axios.post("/api/list");
                if ("status" in response.data && response.data.status) {

                } else {
                   
                }
            }
        },
        mounted() {
            // if (!this.$store.state.loginStatus) {
            //     this.$message({
            //         showClose: true,
            //         message: '你还没有登录= =',
            //         type: 'error'
            //     });
            //     this.$router.push('/exercise/login')
            // }
            this.RequestList();
        }
    }
</script>

<style scoped>
    .el-select-width {
        width: 130px;
    }

    .input-with-select {
        background-color: #fff;
        width: 70%;
    }
</style>