<template>
    <div id="app">
        <el-container>
            <el-header class="el-header-menu">
                <el-menu mode="horizontal" default-active="2"  background-color="#545c64"
                         text-color="#fff" active-text-color="#ffd04b" :router="true">
                    <el-menu-item index="2" route="/">
                        <i class="el-icon-menu"></i>
                        <span slot="title">首页</span>
                    </el-menu-item>
                    <el-menu-item index="3" route="/about">
                        <i class="el-icon-document"></i>
                        <span slot="title">预约</span>
                    </el-menu-item>
                </el-menu>
            </el-header>
            <router-view/>
            <el-footer>

            </el-footer>
        </el-container>
    </div>
</template>

<style>
    #app {
        font-family: 'Avenir', Helvetica, Arial, sans-serif;
        -webkit-font-smoothing: antialiased;
        -moz-osx-font-smoothing: grayscale;
        text-align: center;
        color: #2c3e50;
    }

    body{
        margin: 0;
    }

    .el-header-menu{
        padding: 0;
    }
</style>
